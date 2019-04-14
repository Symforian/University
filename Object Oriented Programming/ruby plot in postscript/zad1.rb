class Proc


	def value(x)
		self.call(x)

	end
	
	def zerowe(a, b, e)
		zeros=[]
		i = a.to_i
		for i in i..b
			val = value(i)
			if val >= -e and val <= e
				zeros+=[i]
			end
		end
		return zeros		
	end


	#e - precyzja
	def pole(a, b, e)
			
		p = 0.0
		h = (b-a)/e
	
		for i in 1..e
			yi = value(a + (i-1)*h)
			yi /= 2 if i == 1 or i == e
			p += h*yi
		end

		return p
	end
	#h - precyzja
	def poch(x,h)
		return (value(x+h) - value(x)) / h
	end

	def rysuj(a, b, nazwa)

		file = File.open(nazwa, "w")
		file.puts "%!PS"
		
		x = 400
		y = 400
		
		dx = (b - a) / x.to_f
		h = y / 2
		
		file.puts "0 " + (value(a) + h).to_s + " moveto"
	       
		for i in 1..x
		    file.puts i.to_s + " " + (value(a + i * dx) + h).to_s + " lineto"
		end


		file.puts "0 "+h.to_s+" "+" moveto"
		file.puts "0 "+h.to_s+" "+" lineto"
		file.puts x.to_s+" "+h.to_s+" "+" lineto"

		if a<0 and b>0
			podz=-a+b
			podz=x/podz
			s=0
			i=a.to_i
			for i in (a.to_i)...0
				s+=podz
			file.puts s.to_s+" "+"0 "+" moveto"
			end
			file.puts s.to_s+" "+x.to_s+" "+" lineto"
			

		end
		file.puts "stroke"
		file.puts "showpage"		

		file.close
	end

end

puts "f(x) = x^2 *sin(x) "
f = proc { |x| x*x * Math.sin(x) }

puts "f(10) = ", f.value(10.0).round(1)
puts "miejsce zerowe na [-1,2] : ", f.zerowe(-1.0, 2.0, 0.0000001)
puts "pochodna w punkcie 4 wynosi ", f.poch(4.0,0.00000001).round(1)
puts "pole pod wykresem na przedziale [-1, 2] jest rowne ", f.pole(-1.0, 2.0,1000).round(1)
puts "pole pod wykresem na przedziale [-1, 2] z niska precyzja jest rowne ", f.pole(-1.0, 2.0,100).round(1)
puts "pole pod wykresem na przedziale [-1, 2] z b. niska precyzja jest rowne ", f.pole(-1.0, 2.0,10).round(1)
puts "pole pod wykresem na przedziale [-1, 2] z b. b. niska precyzja jest rowne ", f.pole(-1.0, 2.0,2).round(1)
f.rysuj(-100.0,100.0,"wykres_f")

puts "\ng(x) = x^2 "
g = proc { |x| x*x }

puts "g(10) = ", g.value(10.0).round(1)
puts "miejsce zerowe na [-10,10] : ", g.zerowe(-10.0, 10.0, 0.00001).to_s
puts "pochodna w punkcie 4 wynosi ", g.poch(4.0,0.00000001).round(1)
puts "pole pod wykresem na przedziale [-1, 2] jest rowne ", g.pole(-1.0, 2.0,1000).round(1)
g.rysuj(-50.0,50.0,"wykres_g")

