/*

The MIT License (MIT)

Copyright (c) 2015 Bondan Sumbodo <sybond@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

/*
	Main readQ source file
*/

#define _SVID_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/time.h>
#include "bnd_util.h"

#define __SCCSver__ "@(#)readq_main.c 1.0 2015/08/08 Bondan Sumbodo (sybond@gmail.com)"
static char * __SCCSVer_readQ__ = __SCCSver__;


void copyright(){
	printf("readQ - Read specific ipc queue id, dump to stdout and restore it back to ipc queue stack.\n");
	printf("Copyright (c) 2015 Bondan Sumbodo <sybond@gmail.com>\n\n");
}

void usage(char *argv[]){
	printf("Usage:\n");
	printf("     %s [qid]\n\n",argv[0]);
}

int main(int argc, char *argv[]) {
	copyright();
	if (argc > 1) {
		int resp, len, qid = atoi(argv[1]);
		printf("%s processing with qid=%d..\n",tstamp(),qid);
		char data[1024];
		memset(&data, 0, 1024);
		printf("%s trying to read Q with ID=%d\n",tstamp(), qid);
		len = msgrcv(qid, &data, 1024, 0, MSG_NOERROR);
		printf("%s received length=%d\n", tstamp(), len);
		if (len>0) {
			printf("%s dumping Q data:\n",tstamp());
			hexDump(NULL , &data, len);
			printf("%s trying to put it back to the Q\n",tstamp());
			resp = msgsnd(qid, &data, len, 0);
			printf("%s resp=%d\n", tstamp(), resp);
			if (resp==0) printf("%s done!\n",tstamp());
		}
	} else {
		usage(argv);
	}
}
