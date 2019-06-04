/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2019, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at https://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include <stdio.h>
#include <curl/curl.h>

/*
 * 从FTP服务器中下载单个文件
*/

struct FtpFile
{
  const char *filename;
  FILE *stream;
};

static size_t my_fwrite(void *buffer, size_t size, size_t nmemb, void *stream)
{
  struct FtpFile *out = (struct FtpFile *)stream;
  printf("Now in the Callback \n");

  if (!out->stream)
  {
    /* open file for writing */
    out->stream = fopen(out->filename, "wb");
    if (!out->stream)
      return -1; /* failure, can't open file to write */
  }

  return fwrite(buffer, size, nmemb, out->stream);
}

int main(void)
{
  CURL *curl;
  CURLcode res;
  struct FtpFile ftpfile = {
      "DownReadme.md", /* name to store the file as if successful */
      NULL};

  curl_global_init(CURL_GLOBAL_DEFAULT);

  // 初始化curl
  curl = curl_easy_init();
  if (curl)
  {
    // 指定下载FTP文件地址,以及用户名密码
    curl_easy_setopt(curl, CURLOPT_URL, "ftp://172.21.16.26/CertusNetOAM/README.md");
    curl_easy_setopt(curl, CURLOPT_USERPWD, "root:");

    // 从FTP服务器下载完成之后并写文件的回调函数注册
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_fwrite);

    // 指定文件名
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &ftpfile);

    /* Switch on full protocol/debug output */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);

    if (CURLE_OK != res)
    {
      /* we failed */
      fprintf(stderr, "curl told us %d\n", res);
    }
  }

  if (ftpfile.stream)
    fclose(ftpfile.stream); /* close the local file */

  curl_global_cleanup();

  return 0;
}
