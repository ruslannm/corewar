#by rgero
.name	"Bomber"
.comment "Do the right thing"
	
ld %2, r3
add r2, r3, r2 
sti r1, r2, %5
live %1
