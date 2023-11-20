#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int isLeapYear(int year) {
  if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
    return 1;
  }
  return 0;
}

int checkDate(int day, int month, int year) {
  if (year < 1 || year > 9999) {
    return 0;
  }
  if (month < 1 || month > 12) {
    return 0;
  }
  if (day < 1 || day > 31) {
    return 0;
  }
  if (month == 2) {
    if (isLeapYear(year)) {
      if (day > 29) {
        return 0;
      }
    } else {
      if (day > 28) {
        return 0;
      }
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day > 30) {
      return 0;
    }
  }
  return 1;
}

int main() {
  char message[MAX_LEN];
  int valid_dates = 0;
  double max_size = -1;
  while (1) {
    fgets(message, MAX_LEN, stdin);
    if (message[0] == '$') {
      break;
    }
    int day, month, year, blocked;
    char sender[MAX_LEN], receiver[MAX_LEN];
    double size;
    char size_unit;
    sscanf(message, "%d-%d-%d %s %lf%c %s %d", &day, &month, &year, sender,
           &size, &size_unit, receiver, &blocked);
    if (checkDate(day, month, year)) {
      valid_dates++;
    }
    switch (size_unit) {
    case 'G':
      size *= 1024;
    case 'M':
      size *= 1024;
    case 'K':
      size *= 1024;
      break;
    default:
      break;
    }
    if (size > max_size) {
      max_size = size;
    }
  }
  printf("Số lượng tin nhắn hợp lệ: %d\n", valid_dates);
  printf("Tin nhắn có dung lượng lớn nhất: %lf bytes\n", max_size);
  return 0;
}/*bai 2*/