const noteForm = document.getElementById('noteForm');
const noteInput = document.getElementById('noteInput');
const notesList = document.getElementById('notesList');

// Load notes from cookies on page load
document.addEventListener('DOMContentLoaded', loadNotesFromCookies);

noteForm.addEventListener('submit', (event) => {
  event.preventDefault();
  addNote();
});

function addNote() {
  const noteText = noteInput.value.trim();
  if (noteText === '') return;

  const notes = getNotes();
  notes.push(noteText);
  setNotes(notes);
  noteInput.value = '';
  displayNotes();
}

function displayNotes() {
  const notes = getNotes();
  notesList.innerHTML = '';
  notes.forEach((note, index) => {
    const noteElement = document.createElement('div');
    noteElement.classList.add('note');

    noteElement.innerHTML = `
      <p>${note}</p>
      <button class="edit-button" onclick="editNote(${index})">Edit</button>
      <button class="delete-button" onclick="deleteNote(${index})">Delete</button>
    `;

    notesList.appendChild(noteElement);
  });
}

function editNote(index) {
  const notes = getNotes();
  const newText = prompt("Edit your note:", notes[index]);
  if (newText !== null && newText.trim() !== '') {
    notes[index] = newText.trim();
    setNotes(notes);
    displayNotes();
  }
}

function deleteNote(index) {
  const notes = getNotes();
  notes.splice(index, 1);
  setNotes(notes);
  displayNotes();
}

// Get notes from cookies
function getNotes() {
  const notes = document.cookie.split('; ').find(row => row.startsWith('notes='));
  return notes ? JSON.parse(decodeURIComponent(notes.split('=')[1])) : [];
}

// Set notes in cookies
function setNotes(notes) {
  const now = new Date();
  now.setTime(now.getTime() + (30 * 24 * 60 * 60 * 1000)); // 30 days expiration
  document.cookie = `notes=${encodeURIComponent(JSON.stringify(notes))}; expires=${now.toUTCString()}; path=/`;
}

// Load notes from cookies on page load
function loadNotesFromCookies() {
  displayNotes();
}
