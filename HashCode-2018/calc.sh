A=$(python score.py a_example.in a.sol)
B=$(python score.py b_should_be_easy.in b.sol)
C=$(python score.py c_no_hurry.in c.sol)
D=$(python score.py d_metropolis.in d.sol)
E=$(python score.py e_high_bonus.in e.sol)
ans=$((A+B+C+D+E))
echo $ans
