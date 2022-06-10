/*
 * src/core/device.c
 * Stanislaw Grams <sjg@haxx.space>
 *
 * 2022, haxx.space, fmdx.pl
 * For license information, see LICENSE
 */
#include "include/device.h"

void test ();

int main (void) {
  test ();
  return 0;
}

void test () {
  size_t length;

  SoapySDRKwargs *results = SoapySDRDevice_enumerate(NULL, &length);

  for (size_t i = 0; i < length; i++)
  {
      printf("Found device #%d: ", (int)i);
      for (size_t j = 0; j < results[i].size; j++)
      {
          printf("%s=%s, ", results[i].keys[j], results[i].vals[j]);
      }
      printf("\n");
  }
  SoapySDRKwargsList_clear(results, length);

  //create device instance
  //args can be user defined or from the enumeration result
  SoapySDRKwargs args = {};
  SoapySDRKwargs_set(&args, "driver", "airspyhf");
  SoapySDRDevice *sdr = SoapySDRDevice_make(&args);
  SoapySDRKwargs_clear(&args);

  if (sdr == NULL)
  {
      printf("SoapySDRDevice_make fail: %s\n", SoapySDRDevice_lastError());
      return;
  }

  //cleanup device handle
  SoapySDRDevice_unmake(sdr);
}

core_device_info_list_t *
core_device_info_list_get_available () {
}

core_device_inst_t *
core_device_inst_create(struct core_device_info *info) {
  core_device_inst_t *inst;
  if (type == none ||
      !info) {
    return NULL;
  }
}

void
core_device_inst_destroy(core_device_inst_t **inst) {
  if (!inst) {
    assert(0);
    return;
  }
  *inst = NULL;
}

