.name	"Leeloo"
.comment "Multipass"
	
begin:	ld %0,r6
jump:	zjmp %:deb
	
deb:	st r16, :begin
