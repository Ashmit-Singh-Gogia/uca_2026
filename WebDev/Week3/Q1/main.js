// main.js
if (window.Worker) {
    // Create a new Web Worker
    const userWorker = new Worker('worker.js');

    // Trigger worker execution
    userWorker.postMessage('fetchUsers');

    // Listen for messages from worker
    userWorker.onmessage = (event) => {
        const { success, users, error } = event.data;

        if (success) {
            // Print formatted output to console
            users.forEach(userString => console.log(userString));
        } else {
            // Console error handling
            console.error(`Failed to fetch users: ${error}`);
        }

        // Terminate worker after completion
        userWorker.terminate();
    };

    // Handle worker-level script errors
    userWorker.onerror = (error) => {
        console.error("An error occurred inside the Web Worker:", error.message);
        userWorker.terminate();
    };

} else {
    console.error("Web Workers are not supported in this browser.");
}