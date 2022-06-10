/*
 * src/core/include/device.h
 * Stanislaw Grams <sjg@haxx.space>
 *
 * 2022, haxx.space, fmdx.pl
 * For license information, see LICENSE
 */
#ifndef _SQUARESDR_CORE_INCLUDE_DEVICE_H
#define _SQUARESDR_CORE_INCLUDE_DEVICE_H

#include <glib.h>

#include <SoapySDR/Device.h>
#include <SoapySDR/Formats.h>

#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

enum core_device_type {
  none,
  airspyhf,
  sdrplay
};

struct core_device_info {
  enum core_device_type type;
  gchar                 *label
  gchar                 *sn;
};

typedef core_device_info_list_t

typedef struct {
  SoapySDRDevice          *device;
  struct core_device_info info;
} core_device_inst_t;

#endif // _SQUARESDR_CORE_INCLUDE_DEVICE_H
