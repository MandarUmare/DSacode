class Human:
    population=0#class member
    def __init__(self,name,gender):
        self.gender=gender#gender local self.gender instance member
        self.name=name
        Human.population+=1
        print("New human created total population:",Human.population)
    def __del__(self):
        print("R.I.P:",self.name)
    def __str__(self):
        return "hi i am a "+self.gender+" named "+self.name
    
h=Human("amar","male")
h=Human("Hulk","male")
h3=Human("uman","male")