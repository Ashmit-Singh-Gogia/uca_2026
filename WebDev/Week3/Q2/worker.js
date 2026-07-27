// worker.js
self.onmessage = async () => {
    try {
        const response = await fetch('https://dummyapi.com/users');

        if (!response.ok) {
            throw new Error(`HTTP error! Status: ${response.status}`);
        }

        const data = await response.json();

        // Check if response is empty or invalid
        if (!data || !Array.isArray(data) || data.length === 0) {
            throw new Error("No users found");
        }

        // Process and format each user
        const usersList = data.map(user => {
            const status = user.active ? "Active" : "Inactive";
            return `${user.name} - ${status}`;
        });

        // Post successful response back to main thread
        self.postMessage({ success: true, users: usersList });

    } catch (error) {
        // Send error message back to main thread
        self.postMessage({ success: false, message: error.message });
    }
};