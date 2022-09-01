if [ $# -eq 0 ]
then
	echo "No argument given"
	echo "please pass a comment as an argument"
	exit
fi
git add .


git push origin main

#############################
bruh=""
for i;
do
	bruh="$bruh $i"
done
#############################

git commit -m "$bruh"


git push origin main
