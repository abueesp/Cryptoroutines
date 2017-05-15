asciibin () {
read -p "Introduce ascii string: " ASC
echo $ASCII | perl -lpe '$_=join " ", unpack"(B8)*"'
echo $ASC >> ASCII
xxd -b ASCII
rm ASCII
}

alias asciioct='read -p "Introduce ascii string: " ASC; echo $ASC >> ASCII; echo "ibase=16;obase=8; $(xxd -ps -u ASCII)" | bc; rm ASCII'
alias asciihex='read -p "Introduce ascii string: " ASC; echo $ASC >> ASCII; xxd -ps -u ASCII; rm ASCII'
alias asciic='read -p "Introduce ascii string: " ASC; echo $ASC >> ASCII; xxd -i $ASCII; rm ASCII'

alias decbin='read -p "Introduce dec number: " DEC; echo "obase=2; $DEC" | bc'
alias decoct='read -p "Introduce dec number: " DEC; echo "obase=8; $DEC" | bc'
alias dechex='read -p "Introduce dec number: " DEC; echo "obase=16; $DEC" | bc'

binascii () {
read -p "Introduce bin number: " BIN; 
echo $BIN| perl -lape '$_=pack"(B8)*",@F'
}
alias bindec='read -p "Introduce bin number: " BIN; echo "ibase=2; $BIN | bc'
alias binoct='read -p "Introduce bin number: " BIN; echo "ibase=2;obase=8; $BIN" | bc'
alias binhex='read -p "Introduce bin number: " BIN; echo "ibase=2;obase=16; $BIN" | bc'

alias octascii='read -p "Introduce oct number: " OCT; echo "ibase=8;obase=16; $OCT" >> OCTY; xxd -r -p $OCTY; rm OCTY' 
alias octbin='read -p "Introduce oct number: " OCT; echo "ibase=8;obase=2; $OCT" | bc'
alias octdec='read -p "Introduce oct number: " OCT; echo "ibase=8; $OCT" | bc'
alias octhex='read -p "Introduce oct number: " OCT; echo "ibase=8;obase=16; $OCT" | bc'

alias hexascii='read -p "Introduce hex number: " HEX; echo $HEX >> HEXY; xxd -r -p $HEXY; rm HEXY' 
alias hexdec='read -p "Introduce hex number: " HEX; echo "ibase=16; $HEX" | bc'
alias hexbin='read -p "Introduce hex number: " HEX; echo "ibase=16;obase=2; $HEX" | bc; echo $((0x$HEX))'
alias hexoct='read -p "Introduce hex number: " HEX; echo "ibase=16;obase=8; $HEX" | bc'

