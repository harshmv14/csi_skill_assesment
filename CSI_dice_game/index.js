var p1;
var p2;

    p1 = Math.random();
    p1 = p1 * 6;
    p1 = Math.floor(p1);
    p1 = p1 + 1;
    p2 = Math.random();
    p2 = p2 * 6;
    p2 = Math.floor(p2);
    p2 = p2 + 1;


document.onload = play();

function play(){
    document.querySelector(".img1").setAttribute("src", `/img/dice${p1}.png`);
    document.querySelector(".img2").setAttribute("src", `/img/dice${p2}.png`);
};

if (p1 > p2){
    document.querySelector("h1").innerHTML = "Player One Wins";
} else if (p1 === p2){
    document.querySelector("h1").innerHTML = "Its a Tie, Try Again!";
} else{
    document.querySelector("h1").innerHTML = "Player Two Wins";
}