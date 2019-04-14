CFLAGS = -std=gnu99 -Wall -Wextra
CO = gcc -c
all: traceroute

traceroute: traceroute.o send_icmp.o receive_icmp.o 

traceroute.o: traceroute.c traceroute.h
	$(CO) $(CFLAGS) traceroute.c 

send_icmp.o: send_icmp.c traceroute.h
	$(CO) $(CFLAGS) send_icmp.c 

receive_icmp.o: receive_icmp.c traceroute.h
	$(CO) $(CFLAGS) receive_icmp.c 

clean: 
	rm -f *.o
distclean: clean
	rm -f traceroute
