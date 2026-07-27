// main.js
document.addEventListener('DOMContentLoaded', () => {
    const container = document.getElementById('users');

    if (!window.Worker) {
        container.textContent = "Web Workers are not supported in this browser.";
        return;
    }

    // Create the Web Worker
    const worker = new Worker('worker.js');

    // Trigger worker task
    worker.postMessage('FETCH');

    // Handle message from worker
    worker.onmessage = (event) => {
        const { success, users, message } = event.data;

        if (success) {
            // Clear container and append formatted user rows
            container.innerHTML = '';
            users.forEach(userText => {
                const item = document.createElement('div');
                item.textContent = userText;
                container.appendChild(item);
            });
        } else {
            // Display fallback UI ("No users found" or error message)
            container.textContent = message.includes("No users found")
                ? "No users found"
                : `Error: ${message}`;
        }

        worker.terminate();
    };

    // Handle worker execution errors
    worker.onerror = (err) => {
        container.textContent = "No users found";
        console.error("Worker error:", err);
        worker.terminate();
    };
});