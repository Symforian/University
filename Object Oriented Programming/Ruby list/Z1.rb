class Fixnum
	def czynniki
		czyn=[]
		for i in 1...self+1
			czyn+=[i] if self%i==0
		end
		return czyn.to_s
	end
	def prime?
		n = self
		return false if n < 2
		for i in 2...n
			return false if n % i == 0
		end
		return true
	end

	def ack(x)
		return x+1 if self == 0
		return (self - 1).ack(1) if x == 0
		return (self-1).ack(self.ack(x-1))
	end

	def doskonala?
	
		sum = 0
		for i in 1...(self-1)
			sum = sum + i if self % i == 0
		end
		
		return (sum == self)
	end

	Tab = ["zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięc"]

	def slownie
		return "" if self == 0
		last = self % 10
		reszta = self / 10
		return "" + reszta.slownie + Tab[last] + " "
	end

end
#############
puts "Is prime"
puts 17,17.prime?,933243,933243.prime?,8,8.prime?,9,9.prime?,0,0.prime?

puts "","Doskonala",6,6.doskonala?,28,28.doskonala?,32,32.doskonala?,""

puts "Slownie",1234567890,1234567890.slownie,13423,13423.slownie


puts "F-cja Ackermanna",""
puts "m/n\t0\t1\t2\t3\t4",""
print "0\t",0.ack(0),"\t",0.ack(1),"\t",0.ack(2),"\t",0.ack(3),"\t",0.ack(4),"\n"
print "1\t",1.ack(0),"\t",1.ack(1),"\t",1.ack(2),"\t",1.ack(3),"\t",1.ack(4),"\n"
print "2\t",2.ack(0),"\t",2.ack(1),"\t",2.ack(2),"\t",2.ack(3),"\t",2.ack(4),"\n"
print "3\t",3.ack(0),"\t",3.ack(1),"\t",3.ack(2),"\t",3.ack(3),"\t",3.ack(4),"\n"

puts 6.czynniki
puts 0.czynniki
puts 32.czynniki
