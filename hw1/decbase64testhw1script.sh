#!/bin/sh

#  decbase64testhw1script.sh
#  hw1
#
#  Created by Ulan Korabay on 1/29/16.
#  Copyright (c) 2016 Ulan Korabay. All rights reserved.
set srcdir=~csci531/public/cs531/hw1

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.dat
foreach f (5 6 7 9)
echo "===> $srcdir/f$f"
./hw1 dec-base64 $srcdir/f$f.b64 > f$f.dat
diff $srcdir/f$f f$f.dat
end

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.dat
foreach f (0 1 2 3 9)
echo "===> $srcdir/f$f"
cat $srcdir/f$f.b64 | ./hw1 dec-base64 > f$f.dat
diff $srcdir/f$f f$f.dat
end

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f100.dat f101.dat
foreach f (100 101)
echo "===> $srcdir/f$f"
cat $srcdir/f$f.b64 | ./hw1 dec-base64 > f$f.dat
diff $srcdir/f$f f$f.dat
end
