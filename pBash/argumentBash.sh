#!/bin/bash
echo $HOSTNAME
echo $USER
if [ "$1" != "" ]; then
  echo "Positional parameter 1 contains something"
else
  echo "Positional parameter 1 is empty"
fi
if [ "$1" != "" ]; then 
  cat $1 > in_m
  echo "What you enteres is" $in_m 
fi
