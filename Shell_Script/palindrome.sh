echo "Enter the number"
read num
n=$num
f=0
p=0
while [ $num -gt 0 ] 
do
    echo "Inside loop"
    p=$(( $num % 10 ))
    num=$(( $num / 10 ))
    f=$(( $f * 10 + $p ))
done
if [ $f -eq $n ] ;
then
echo "Palindrome"
else
    echo "Not a Palindrome"
fi