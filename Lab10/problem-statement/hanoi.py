def hanoi(sz, src, dest, extra):
	if not (sz==0): 
		hanoi(sz-1,src,extra,dest)
		print("move a disk from ",src," to ",dest)
		hanoi(sz-1,extra,dest,src)

hanoi(3, "A", "B", "C")
