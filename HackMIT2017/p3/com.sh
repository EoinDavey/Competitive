out="$2 $1"
echo $out
curl -s -k -X 'POST' -b '_ga=GA1.2.67414854.1499087896; _gid=GA1.2.139767299.1499243934' -F username=EoinDavey -F codeword="$out" 'https://the.delorean.codes/api/decode'
