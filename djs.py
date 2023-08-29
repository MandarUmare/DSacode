class Human:
    def __init__(self,name,gender):
        print("init called:")
        self.gender=gender
        self.name=name
        print("Human called",self.name,"created")
    def __del__(self):
        print("R.I.P:",self.name)
    def __str__(self):
        return "hi i am a "+self.gender+" named "+self.name

h