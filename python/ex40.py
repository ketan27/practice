class Song(object):

    def __init__(self, lyrics):
        self.lyrics = lyrics
        self.nums = 0

    def sing_me_a_song(self):
        for line in self.lyrics:
            print line
            self.nums += 1

    def song_numbers(self):
        print "The song in this album has %d lines." % self.nums

happy_bday = Song(["Happy birthday to you",
                   "I don't want to get sued",
                   "So I'll stop right there"])

bulls_on_parade = Song(["They rally around the family",
                        "With pockets full of shells"])

happy_bday.sing_me_a_song()
happy_bday.song_numbers()
happy_bday.nums = 100
happy_bday.song_numbers()

print '-' * 20

bulls_on_parade.sing_me_a_song()
bulls_on_parade.song_numbers()
