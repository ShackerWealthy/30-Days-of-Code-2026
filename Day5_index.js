const boardElement = document.getElementById('board');
const cells = document.querySelectorAll('.cell');
const statusText = document.getElementById('status');
const resetBtn = document.getElementById('reset-btn');
const overlay = document.getElementById('overlay');
const resultText = document.getElementById('result-text');

let currentPlayer = 'X';
let gameState = ["", "", "", "", "", "", "", "", ""];
let gameActive = true;

const xIcon = '<svg viewBox="0 0 24 24" stroke="#00f2ff" stroke-width="2" fill="none"><path d="M18 6L6 18M6 6l12 12"/></svg>';
const oIcon = '<svg viewBox="0 0 24 24" stroke="#ff007a" stroke-width="2" fill="none"><circle cx="12" cy="12" r="9"/></svg>';

const winningConditions = [
    [0, 1, 2], [3, 4, 5], [6, 7, 8],
    [0, 3, 6], [1, 4, 7], [2, 5, 8],
    [0, 4, 8], [2, 4, 6]
];

function handleCellClick(e) {
    const clickedCell = e.target.closest('.cell');
    const index = parseInt(clickedCell.getAttribute('data-index'));

    if (gameState[index] !== "" || !gameActive) return;

    gameState[index] = currentPlayer;
    clickedCell.innerHTML = currentPlayer === 'X' ? xIcon : oIcon;
    
    checkResult();
}

function checkResult() {
    let roundWon = false;
    let winningLine = [];

    for (let i = 0; i < winningConditions.length; i++) {
        const [a, b, c] = winningConditions[i];
        if (gameState[a] && gameState[a] === gameState[b] && gameState[a] === gameState[c]) {
            roundWon = true;
            winningLine = [a, b, c];
            break;
        }
    }

    if (roundWon) {
        showGameOver(`PLAYER ${currentPlayer} WINS!`, winningLine);
        gameActive = false;
        return;
    }

    if (!gameState.includes("")) {
        showGameOver("SYSTEM DRAW", []);
        gameActive = false;
        return;
    }

    currentPlayer = currentPlayer === "X" ? "O" : "X";
    statusText.innerHTML = `PLAYER <span class="${currentPlayer === 'X' ? 'neon-blue' : 'neon-pink'}">${currentPlayer}</span> TURN`;
}

function showGameOver(message, line) {
    resultText.innerText = message;
    resultText.style.color = message.includes('DRAW') ? 'white' : (currentPlayer === 'X' ? '#00f2ff' : '#ff007a');
    
    line.forEach(index => cells[index].classList.add('win-cell'));

    setTimeout(() => {
        overlay.classList.remove('hidden');
    }, 600);
}

function resetGame() {
    currentPlayer = "X";
    gameState = ["", "", "", "", "", "", "", "", ""];
    gameActive = true;
    statusText.innerHTML = `PLAYER <span class="neon-blue">X</span> TURN`;
    overlay.classList.add('hidden');
    cells.forEach(cell => {
        cell.innerHTML = "";
        cell.classList.remove('win-cell');
    });
}

cells.forEach(cell => cell.addEventListener('click', handleCellClick));
resetBtn.addEventListener('click', resetGame);
overlay.addEventListener('click', resetGame);
