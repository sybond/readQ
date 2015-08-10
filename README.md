# readQ
Small utility to read specific ipc queue id message, dump to stdout and restore it back to ipc queue stack.

Example of usage
-----

```/sybond/posix>./readQ 1157627996
readQ - Read specific ipc queue id, dump to stdout and restore it back to ipc queue stack.
Copyright (c) 2015 Bondan Sumbodo <sybond@gmail.com>

[2015/08/10 10:07:18.704108] processing with qid=1157627996..
[2015/08/10 10:07:18.704333] trying to read Q with ID=1157627996
[2015/08/10 10:07:45.326352] received length=56
[2015/08/10 10:07:45.326411] dumping Q data:
  0000  00 01 5f 92 ff ff ff 00 00 00 00 00 00 00 00 00  .._.............
  0010  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
  0020  00 00 00 00 00 00 00 53 00 00 00 00 00 00 00 00  .......S........
  0030  00 00 00 00 00 00 00 00                          ........
[2015/08/10 10:07:45.326478] trying to put it back to the Q
[2015/08/10 10:07:45.326525] resp=0
[2015/08/10 10:07:45.326538] done!
```
