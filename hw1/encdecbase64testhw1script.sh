#!/bin/sh

#  encdecbase64testhw1script.sh
#  hw1
#
#  Created by Ulan Korabay on 1/29/16.
#  Copyright (c) 2016 Ulan Korabay. All rights reserved.
set srcdir=~csci531/public/cs531/hw1

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.dat
foreach f (0 1 2 3 4 5 6 7 8 9)
echo "===> $srcdir/f$f"
./hw1 enc-base64 $srcdir/f$f | ./hw1 dec-base64 > f$f.dat
diff $srcdir/f$f f$f.dat
end
