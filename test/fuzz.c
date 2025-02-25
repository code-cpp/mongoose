#include "mongoose.h"

#ifdef __cplusplus
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *, size_t);
#else
int LLVMFuzzerTestOneInput(const uint8_t *, size_t);
#endif

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  mg_log_set("0");

  struct mg_dns_message dm;
  mg_dns_parse(data, size, &dm);
  mg_dns_parse(NULL, 0, &dm);

  struct mg_http_message hm;
  mg_http_parse((const char *) data, size, &hm);
  mg_http_parse(NULL, 0, &hm);

  struct mg_str body = mg_str_n((const char *) data, size);
  char tmp[256];
  mg_http_get_var(&body, "key", tmp, sizeof(tmp));
  mg_http_get_var(&body, "key", NULL, 0);
  mg_url_decode((char *) data, size, tmp, sizeof(tmp), 1);
  mg_url_decode((char *) data, size, tmp, 1, 1);
  mg_url_decode(NULL, 0, tmp, 1, 1);

  struct mg_mqtt_message mm;
  mg_mqtt_parse(data, size, &mm);
  mg_mqtt_parse(NULL, 0, &mm);

  mg_sntp_parse(data, size);
  mg_sntp_parse(NULL, 0);

  char buf[size * 4 / 3 + 5];  // At least 4 chars and nul termination
  mg_base64_decode((char *) data, (int) size, buf);
  mg_base64_decode(NULL, 0, buf);
  mg_base64_encode(data, (int) size, buf);
  mg_base64_encode(NULL, 0, buf);

  mg_globmatch((char *) data, size, (char *) data, size);

  struct mg_str k, v, s = mg_str_n((char *) data, size);
  while (mg_commalist(&s, &k, &v)) k.len = v.len = 0;

  int n;
  mg_json_get((char *) data, (int) size, "$", &n);

  return 0;
}
