#!/bin/sh

#  testhw1script.sh
#  hw1
#
#  Created by Ulan Korabay on 1/29/16.
#  Copyright (c) 2016 Ulan Korabay. All rights reserved.
set srcdir=~csci531/public/cs531/hw1

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.hex f??.hex
foreach f (0 1 2 3 4 5 6 7 8)
echo "===> $srcdir/f$f"
./hw1 hexdump $srcdir/f$f > f$f.hex
diff $srcdir/f$f.hex f$f.hex
end

#
# for the following commands, each correct answer gets 1 point
#
/bin/rm -f f?.hex f??.hex
foreach f (9 10 11 12 13 14)
echo "===> $srcdir/f$f"
cat $srcdir/f$f | ./hw1 hexdump > f$f.hex
diff $srcdir/f$f.hex f$f.hex
end
