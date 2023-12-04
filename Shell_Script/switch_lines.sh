read -p "Enter your choice" ch
case $ch in
1) groups ;;
2) echo "Enter the file name"
read file
echo "Enter the number of lines"
read num
awk "NR>=0 && NR<=$num" $file ;;
*) echo "Wrong Input" ;;
esac
