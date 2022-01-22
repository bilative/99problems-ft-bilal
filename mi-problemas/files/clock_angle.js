function clockAngle(hour, minute){
    hour_loc = (hour * 30) + (minute * 30 / 60)
    minute *= 6
    let result = Math.abs(hour_loc - minute)
    
    if (result > 180){
        result = 360 - result
    }
    return result
}


trials = [
    [0, 0],
    [3, 15],
    [3, 20],
    [3, 45],
    [6, 30],
    [9, 15]
]


for(let i = 0; i < trials.length; i++){
    console.log(clockAngle(trials[i][0], trials[i][1]))
}

// 0
// 7.5
// 20
// 157.5
// 15
// 172.5