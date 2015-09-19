target: all

all: 
	g++ SoccerPlayer_Library/soccerPlayer.cpp SoccerPlayer_Library/sock.cpp SoccerPlayer_Library/environm.cpp -I./ -o SoccerPlayer_Library/SoccerPlayer

clean: 
	rm SoccerPlayer_Library/SoccerPlayer
