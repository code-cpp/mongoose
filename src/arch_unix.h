#pragma once

#if MG_ARCH == MG_ARCH_UNIX

#define _DARWIN_UNLIMITED_SELECT 1  // No limit on file descriptors

#if !defined(MG_ENABLE_POLL) && (defined(__linux__) || defined(__APPLE__))
#define MG_ENABLE_POLL 1
#endif

#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(MG_ENABLE_POLL) && MG_ENABLE_POLL
#include <poll.h>
#else
#include <sys/select.h>
#endif
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#ifndef MG_ENABLE_DIRLIST
#define MG_ENABLE_DIRLIST 1
#endif

#endif
