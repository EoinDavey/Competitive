lines = ARGF.readlines
$start_pos = lines.map { |line| line.split(" ")[-1].to_i }

class Array
  def add(b)
    return [self[0] + b[0], self[1] + b[1]]
  end
end

def part1
  trn = 0
  rolls = 0
  scrs = [0, 0]
  poss = $start_pos.clone
  die = 0
  while scrs[0] < 1000 and scrs[0] < 1000
    dies = [0,1,2].map {|v| (die + v) % 100 + 1}
    die = dies[-1]
    dv = dies.sum
    rolls += 3
    poss[trn] = (dv + poss[trn] - 1) % 10 + 1
    scrs[trn] += poss[trn]
    trn = 1 - trn
  end
  puts "Part 1: #{[scrs[0], scrs[1]].min * rolls}"
end

$memo = {}
def simQDie(scrs, poss)
  if $memo.key? [scrs, poss]
    return $memo[[scrs, poss]]
  end

  if scrs[1] >= 21
    return [0, 1]
  end

  res = [0,0]
  [1,2,3].product([1,2,3], [1,2,3]).each do |rolls|
    sm = rolls.sum
    npos = [(poss[0] + sm - 1) % 10 + 1, poss[1]]
    nscrs = scrs.add([npos[0], 0])
    res = res.add(simQDie(nscrs.reverse, npos.reverse).reverse)
  end

  $memo[[scrs, poss]] = res
  return res
end

def part2
  puts "Part 2: #{simQDie([0, 0], $start_pos.clone).max}"
end

part1
part2
