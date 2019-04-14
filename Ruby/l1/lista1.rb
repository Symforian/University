def pascal(x)
	if x >= 1
		puts "1"
		index = 2
		line = [1]
		while index<=x 
			line = write(index, line)
			index = index + 1
		end
	end
end


def write(lineNumber, previousLine)
	previousLine.push(1)
	i = previousLine.length - 1
	while i > 0
		previousLine[i] = previousLine[i] + previousLine[i-1]
		i = i - 1 
	end
	puts previousLine * " " + " 1"
	return previousLine
end
puts "Pascal tests"
puts "Pascal 1"
pascal(1)
puts "Pascal 2"
pascal(2)
puts "Pascal 3"
pascal(3)
puts "Pascal 10"
pascal(10)

#  X    X    XXXX  X      XXXXX   XXXX  XXXXXX  XXXX   XXXX   XXXX

# XX  X   X X   XX X  X   X      X          X  X    X X    X X    X

#X X     X     XX  XXXXXX XXXX    XXXX    X     XXXX   XXXX  X    X

#  X   X    X   XX    X       X  X    X  X     X    X      X X    X

#  X  XXXXX  XXXX     X   XXXX    XXXX  X       XXXX   XXXX   XXXX

def wielkaliczba(n)
	str = n.to_s
	index = 1
	for index in 1..5
		line = ""

		for i in 0..n-1
			line << strFrag(str[i],index) 
			
		end
		puts line
	end
end

def strFrag(cyfra, ln)
	if cyfra.nil?
		return ""
	else
		case cyfra 
			when "1"
				case ln
					when 1, 4, 5
						return "  X "
					when 2
						return " XX "
					when 3
						return "X X "
					end
			when "2"
				case ln
					when 1
						return "  X   "
					when 2
						return "X   X "
					when 3
						return "   X  "
					when 4
						return " X    "
					when 5
						return "XXXXX "
					end
			when "3"
				case ln
					when 1, 5
						return " XXXX  "
					when 2, 4
						return "X   XX "
					when 3
						return "   XX  "
					end
			when "4"
				case ln
					when 1
						return "X      "
					when 2
						return "X  X   "
					when 3
						return "XXXXXX "
					when 4, 5
						return "   X   "
					end
			when "5"
				case ln
					when 1, 3 ,5
						return "XXXXX  "
					when 2
						return "X      "
					when 4
						return "     X "
					end
			when "6"
				case ln
					when 1, 3 ,5
						return " XXXX  "
					when 2
						return "X      "
					when 4
						return "X    X "
					end
			when "7"
				case ln
					when 1
						return "XXXXXX "
					when 2
						return "     X "
					when 3
						return "   X   "
					when 4
						return " X     "
					when 5 
						return "X      "
					end
			when "8"
				case ln
					when 1, 3 ,5
						return " XXXX  "
					when 2 , 4
						return "X    X "
					end
			when "9"
				case ln
					when 1, 3 , 5
						return " XXXX  "
					when 2
						return "X    X "
					when 4
						return "     X "
					end
			when "0"
				case ln
					when 1, 5
						return " XXXX  "
					when 2, 3, 4
						return "X    X "
				end
		end
	end
end
puts "\nWielka liczba tests\n"
wielkaliczba(1234)
puts "\n"
wielkaliczba(5678)
puts "\n"
wielkaliczba(9023)
