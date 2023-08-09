inc @r2
mov A,@r1

mcro m1
my cool macro file
endmcro

lea @r1, @r2

mcro m2
my second outside file
endmcro

move B, @r2
lea @r2, @r3