if [ $# -eq 0 ]
then
	echo "No argument given"
	echo "please pass a comment as an argument"
exit
fi
git add .

git commit -m "$1"

git push origin main

