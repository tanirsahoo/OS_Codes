echo "Enter your choice"
read ch
case $ch in
    1) cat file1.txt file2.txt > file3.txt
    head file3.txt
    echo '\n';;
    2) echo "Enter the pattern you want to search"
    read pat
    grep $pat file1.txt;;
    *) echo "Invalid Input"
    ;;
esac
