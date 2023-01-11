#!/bin/bash

if diff std.log ft.log >/dev/null ; then
  echo -e "\033[32mdiff is OK\033[0m" # Outputs OK in green
else
  echo -e "\033[31mdiff is KO\033[0m" # Outputs KO in red
fi

diff std_time.log ft_time.log ;
exit 0