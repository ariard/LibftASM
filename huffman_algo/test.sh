VAR=20 ; while [ $VAR -gt 0 ] ; do ./compress file1 3>STDBUG ; ((VAR-=1)) ; echo $VAR ; done
