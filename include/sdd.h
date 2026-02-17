#ifndef SDD_H
#define SDD_H

bool sd_init();
bool sd_append(const char *path, const char *text);
bool data_recording(const char *timeHM, int t, int h, float dust);

#endif
