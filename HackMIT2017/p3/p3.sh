awk 'NR>='$2' {system("./com.sh \"'"$1"'\" " $0); print NR}' uniqwords.txt | grep -B 5 -A 2 '"well_formed": true'
