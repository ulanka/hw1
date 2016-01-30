#!/bin/sh

#  encbase64testhw1script.sh
#  hw1
#
#  Created by Ulan Korabay on 1/29/16.
#  Copyright (c) 2016 Ulan Korabay. All rights reserved.
set srcdir=~csci531/public/cs531/hw1

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.b64
foreach f (5 6 7 8 9)
echo "===> $srcdir/f$f"
./hw1 enc-base64 $srcdir/f$f > f$f.b64
diff $srcdir/f$f.b64 f$f.b64
end

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.b64
foreach f (0 1 2 3 4 9)
echo "===> $srcdir/f$f"
cat $srcdir/f$f | ./hw1 enc-base64 > f$f.b64
diff $srcdir/f$f.b64 f$f.b64
end
