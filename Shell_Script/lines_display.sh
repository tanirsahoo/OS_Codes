echo "Enter the file name"
read file
count=`sed -n '$=' $file`
echo "The Number of lines in the current file is: $count"
read -p "Enter the starting line from where you want to display the content: " cont
read -p "Enter the number of lines you want to display: " line
line = $(( $line + $cont ))
awk "NR>=$cont && NR<=$line" $file