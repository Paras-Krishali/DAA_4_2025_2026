document.addEventListener('DOMContentLoaded', () => {
    const gridEl = document.getElementById('grid');
    const solveBtn = document.getElementById('solve-btn');
    const clearBtn = document.getElementById('clear-btn');
    const resetBtn = document.getElementById('reset-btn');
    const statusEl = document.getElementById('status');

    const ROWS = 12;
    const COLS = 12;
    let grid = [];
    let startPos = { r: 1, c: 1 };
    let endPos = { r: 10, c: 10 };


    const createGrid = () => {
        gridEl.innerHTML = '';
        grid = [];
        for (let r = 0; r < ROWS; r++) {
            const rowArr = [];
            for (let c = 0; c < COLS; c++) {
                const cell = document.createElement('div');
                cell.classList.add('cell');
                cell.dataset.r = r;
                cell.dataset.c = c;
                
                let type = 'empty';
                if (r === startPos.r && c === startPos.c) {
                    type = 'start';
                    cell.textContent = 'S';
                } else if (r === endPos.r && c === endPos.c) {
                    type = 'end';
                    cell.textContent = 'E';
                }
                
                cell.classList.add(type);
                cell.addEventListener('mousedown', () => toggleWall(r, c));
                cell.addEventListener('mouseenter', (e) => {
                    if (e.buttons === 1) toggleWall(r, c);
                });

                gridEl.appendChild(cell);
                rowArr.push({ type, element: cell });
            }
            grid.push(rowArr);
        }
    };

    const toggleWall = (r, c) => {
        const cell = grid[r][c];
        if (cell.type === 'empty') {
            cell.type = 'wall';
            cell.element.classList.add('wall');
        } else if (cell.type === 'wall') {
            cell.type = 'empty';
            cell.element.classList.remove('wall');
        }
    };


    const solve = async () => {
        clearPath();
        statusEl.textContent = 'Solving...';
        
        const queue = [startPos];
        const visited = new Set();
        const parent = {};

        visited.add(`${startPos.r},${startPos.c}`);
        
        let found = false;
        const directions = [[0, 1], [1, 0], [0, -1], [-1, 0]];

        while (queue.length > 0) {
            const current = queue.shift();
            const { r, c } = current;

            if (r === endPos.r && c === endPos.c) {
                found = true;
                break;
            }


            if (grid[r][c].type === 'empty') {
                grid[r][c].element.classList.add('visited');
                await new Promise(res => setTimeout(res, 10));
            }

            for (const [dr, dc] of directions) {
                const nr = r + dr;
                const nc = c + dc;
                const key = `${nr},${nc}`;

                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && 
                    grid[nr][nc].type !== 'wall' && !visited.has(key)) {
                    
                    visited.add(key);
                    parent[key] = `${r},${c}`;
                    queue.push({ r: nr, c: nc });
                }
            }
        }

        if (found) {
            drawPath(parent);
            statusEl.textContent = 'Path found!';
        } else {
            statusEl.textContent = 'No path possible!';
        }
    };

    const drawPath = (parent) => {
        let curr = `${endPos.r},${endPos.c}`;
        const startKey = `${startPos.r},${startPos.c}`;

        while (curr !== startKey) {
            const [r, c] = curr.split(',').map(Number);
            if (grid[r][c].type === 'empty' || grid[r][c].type === 'end') {
                grid[r][c].element.classList.add('path');
            }
            curr = parent[curr];
        }
    };

    const clearPath = () => {
        for (let r = 0; r < ROWS; r++) {
            for (let c = 0; c < COLS; c++) {
                grid[r][c].element.classList.remove('visited', 'path');
            }
        }
        statusEl.textContent = 'Draw walls and click Solve!';
    };

    const resetAll = () => {
        createGrid();
        statusEl.textContent = 'Draw walls and click Solve!';
    };


    solveBtn.addEventListener('click', solve);
    clearBtn.addEventListener('click', clearPath);
    resetBtn.addEventListener('click', resetAll);

    createGrid();
});
