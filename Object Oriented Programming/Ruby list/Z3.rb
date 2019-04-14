class Jawna

	def initialize(text)
		@text = text
	end

	def to_s
		@text
	end

	def zaszyfruj(klucz)

		pom = ""
		@text.each_char do |i|
			pom+=klucz[i]
		end
		#if klucz >= 0
		#	klucz = klucz % 26
		#else
		#	klucz = (26 - klucz % 26) * -1
		#end
		#puts klucz
		#for i in 0..@text.length-1
		#	if @text[i].ord + klucz > 122
		#		pom += (97 + (@text[i].ord + klucz)%123).chr
		#	else 
		#		if @text[i].ord + klucz >= 97
		#			pom += (@text[i].ord + klucz).chr 
		#		else
		#			pom += (123 - (97-(@text[i].ord + klucz))%97).chr
		#		end
		#	end
		#end

		return Zaszyfrowane.new(pom)

	end
end

class Zaszyfrowane

	def initialize(text)
		@text = text
	end

	def to_s
		@text
	end

	def odszyfruj(klucz)

		pom = ""
		@text.each_char do |i|
			pom+=klucz.key(i)
		end
		#klucz=klucz*-1
		#if klucz >= 0
		#	klucz = klucz % 26
		#else
		#	klucz = (26 - klucz % 26) * -1
		#end
		#puts klucz
		#for i in 0..@text.length-1
		#	if @text[i].ord + klucz > 122
		#		pom += (97 + (@text[i].ord + klucz)%123).chr
		#	else 
		#		if @text[i].ord + klucz >= 97
		#			pom += (@text[i].ord + klucz).chr 
		#		else
		#			pom += (123 - (97-(@text[i].ord + klucz))%97).chr
		#		end
		#	end
		#end

		return Jawna.new(pom)
	end
end
#########
text = Jawna.new("ruby")
puts text
ztext = Zaszyfrowane.new("yaru")


klucz={ 
	'a'=>'b',
	'b'=>'r',
	'r'=>'y',
	'y'=>'u',
	'u'=>'a'
      }
puts text.zaszyfruj(klucz)
puts ztext.odszyfruj(klucz)
