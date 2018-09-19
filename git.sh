#!/bin/sh

git add *
git status
echo "y || n?"
read -p 'answer: ' answer
if [[ "$answer" == "y" ]]
then
	read -p "comment: " comment
	git commit -m "$comment"
	git push
else
	echo Cancelling . . .
fi
