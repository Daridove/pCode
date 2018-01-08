#!/bin/bash
git add ~/pCode/
echo "git add command succefully done!"
if [ "$1" == "" ]; then 
 echo "You have entered no commit message, so using default message"
 git commit -m "automatic git update"
else
  git commit -m $1
fi
git github push --all
echo "git push Done!"
