var mat = new Array(9);
for (let index = 0; index < mat.length; index++) {
    mat[index] = new Array(9);
}

function fillArray() {
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            mat[i][j] = parseInt(document.getElementById(i+""+j).value, 10);
        }
    }
    solveSudoku(0,0);
}

let isSafe = (i, j, no) => {
    for (let k = 0; k < 9; k++) {
        if (mat[i][k] === no || mat[k][j] === no) {
            return false;
        }
    }
    let sx = (Math.floor(i / 3)) * 3;
    let sy = (Math.floor(j / 3)) * 3;
    for (let x = sx; x < sx + 3; x++) {
        for (let y = sy; y < sy + 3; y++) {
            if (mat[x][y] === no) {
                return false;
            }
        }
    }
    return true;
}

let solveSudoku = (i, j) => {
    // base case
    if (i === 9) {
        for (let l = 0; l < 9; l++) {
            for (let k = 0; k < 9; k++) {
                document.getElementById(l+""+k).value = mat[l][k];
            }
        }
        return true;
    }

    // rec case
    if(j === 9){
        return solveSudoku(i+1,0);
    }

    if(mat[i][j] != 0){
        return solveSudoku(i,j+1);
    }

    for(let no = 1;no<=9;no++){
        if(isSafe(i,j,no)){
            mat[i][j] = no;
            let solveSubproblem = solveSudoku(i,j+1);
            if(solveSubproblem){
                return true;
            }
        }
    }
    mat[i][j] = 0;
    return false;
}

function showArray() {
    for (let index = 0; index < 9; index++) {
        for (let j = 0; j < 9; j++) {
            console.log(mat[index][j]);
        }
    }
}

document.getElementById("slvBtn").addEventListener("click", fillArray);