// Copyright 2020 Yuxiao Cao
// yuxiao08

#include <stdio.h>  // for printf
#include <stdlib.h>  // for EXIT_FAILURE, EXIT_SUCCESS
#include <string.h>  // for strcmp, strlen
#include <fcntl.h>  // for open
#include <dirent.h>  // for DIR, struc dirent
#include <unistd.h>  // for close
#include <errno.h>  // for errno
#include <stdbool.h>  // for true
#include <linux/limits.h>  // for NAME_MAX

// Prints out fn's content.
static void PrintFile(char* fn);

int main(int argc, char **argv) {
  // Validate user input.
  if (argc != 2) {
    fprintf(stderr, "Invalid input.\n");
    return EXIT_FAILURE;
  }

  // Open the directory.
  DIR *dirp = opendir(argv[1]);
  if (dirp == NULL) {
    fprintf(stderr, "Could not open directory.\n");
    return EXIT_FAILURE;
  }

  int dir_length = strlen(argv[1]);

  struct dirent *entry;
  entry = readdir(dirp);
  while (entry != NULL) {
    if ((strlen(entry->d_name) >= 4) &&
      strcmp(entry->d_name + (strlen(entry->d_name) - 4), ".txt") == 0) {
      int f_length = strlen(entry->d_name);
      char *rp = (char *) malloc(sizeof(char) * (dir_length + f_length));
      if (rp == NULL) {
      printf("Allocating memory on heap failed.");
      exit(EXIT_FAILURE);
      }
      // Concatenates strings for a relative path.
      int cx;
      cx = snprintf(rp, NAME_MAX + dir_length + 1, argv[1]);
      snprintf(rp + cx, NAME_MAX + 1, "/");
      snprintf(rp + cx + 1, NAME_MAX, entry->d_name);
      // Print current file's content.
      PrintFile(rp);
      free(rp);
    }
    // Move to next entry.
    entry = readdir(dirp);
  }
  // Open the directory.
  closedir(dirp);
  return EXIT_SUCCESS;
}

static void PrintFile(char* fn) {
  int fd = open(fn, O_RDONLY);
  if (fd == -1) {
    printf("Failed to open the file.");
    exit(EXIT_FAILURE);
  }
  // Get the size of the file.
  size_t fs = lseek(fd, 0, SEEK_END) + 1;
  lseek(fd, 0, SEEK_SET);


  char *buf = (char *) malloc(sizeof(char) * fs);
  int bytes_left = fs;
  // Reture value from read().
  int rtr;
  while (bytes_left > 0) {
    // Read content from fd to buf.
    rtr = read(fd, buf, bytes_left);
    if (rtr == -1) {
      if (errno != EAGAIN && errno != EINTR) {
        printf("non-recoverable error occured, read failed.");
        exit(EXIT_FAILURE);
      }
    } else if (rtr == 0) {  // If reachs the end of the file.
      free(buf);
      break;
    }
    // Write from buf to stdout.
    fwrite(buf, sizeof(char), rtr, stdout);
    bytes_left -= rtr;
  }
  close(fd);
}
