import React, { useState } from 'react';
import './App.css';

function App() {
  // State variables to manage the selected values of each dropdown
  const [season, setSeason] = useState('Select Season');
  const [genre, setGenre] = useState('Select Genre');
  const [length, setLength] = useState('Select Length');
  const [rating, setRating] = useState('Select Rating');
  const [gender, setGender] = useState('Select Gender');
  const [year, setYear] = useState('Select Year');

  const [selectedPreferences, setSelectedPreferences] = useState({});

  // Function to handle changes in the dropdowns
  const handleDropdownChange = (category, value) => {
    switch (category) {
      case 'Season':
        setSeason(value);
        break;
      case 'Genre':
        setGenre(value);
        break;
      case 'Length':
        setLength(value);
        break;
      case 'Rating':
        setRating(value);
        break;
      case 'Gender':
        setGender(value);
        break;
      case 'Year':
        setYear(value);
        break;
      default:
        break;
    }
  };

  const logPreferences = () => {
    console.log('Button clicked!');
    const preferences = {
      Season: season !== 'Select Season' ? season : 'N/A',
      Genre: genre !== 'Select Genre' ? genre : 'N/A',
      Length: length !== 'Select Length' ? length : 'N/A',
      Rating: rating !== 'Select Rating' ? rating : 'N/A',
      Gender: gender !== 'Select Gender' ? gender : 'N/A',
      Year: year !== 'Select Year' ? year : 'N/A',
    };

    console.log('Selected Preferences:', preferences);

    // Send preferences to the C++ backend
    fetch('http://localhost:3001/preferences', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify(preferences),
    })
        .then((response) => response.text())
        .then((data) => console.log('Response from server:', data))
        .catch((error) => console.error('Error:', error));

    setSelectedPreferences(preferences);
  };


  return (
    <div className="App">
      <div className="left-section">
        <h2>Choose Your Preferences: </h2>

        {/* Season Dropdown */}
        <div className="dropdown-container">
          <label>Season: </label>
          <select value={season} onChange={(e) => handleDropdownChange('Season', e.target.value)}>
            <option value="Select Season">Select Season</option>
            <option value="Fall">Fall</option>
            <option value="Winter">Winter</option>
            <option value="Spring">Spring</option>
            <option value="Summer">Summer</option>
          </select>
        </div>

        {/* Genre Dropdown */}
        <div className="dropdown-container">
          <label>Genre: </label>
          <select value={genre} onChange={(e) => handleDropdownChange('Genre', e.target.value)}>
            <option value="Select Genre">Select Genre</option>
            <option value="Action">Action</option>
            <option value="Comedy">Comedy</option>
            <option value="Drama">Drama</option>
            <option value="Romance">Romance</option>
            <option value="History">History</option>
            <option value="Adventure">Adventure</option>
            <option value="Animation">Animation</option>
            <option value="Sci-Fi">Sci-Fi</option>
          </select>
        </div>

        {/* Length Dropdown */}
        <div className="dropdown-container">
          <label>Length: </label>
          <select value={length} onChange={(e) => handleDropdownChange('Length', e.target.value)}>
            <option value="Select Length">Select Length</option>
            <option value="Less than 90 minutes">Less than 90 minutes</option>
            <option value="90 min - 180 min">90 min - 180 min</option>
            <option value="180 min - 270 min">180 min - 270 min</option>
            <option value="270+ minutes">270+ minutes</option>
          </select>
        </div>

        {/* Age Rating Dropdown */}
        <div className="dropdown-container">
          <label>Age Rating: </label>
          <select value={rating} onChange={(e) => handleDropdownChange('Rating', e.target.value)}>
            <option value="Select Rating">Select Rating</option>
            <option value="G">G</option>
            <option value="PG">PG</option>
            <option value="PG-13">PG-13</option>
            <option value="R">R</option>
          </select>
        </div>

        {/* Gender Dropdown */}
        <div className="dropdown-container">
          <label>Gender: </label>
          <select value={gender} onChange={(e) => handleDropdownChange('Gender', e.target.value)}>
            <option value="Select Gender">Select Gender</option>
            <option value="Female">Female</option>
            <option value="Male">Male</option>
          </select>
        </div>

        {/* Year Dropdown */}
        <div className="dropdown-container">
          <label>Year Released: </label>
          <select value={year} onChange={(e) => handleDropdownChange('Year', e.target.value)}>
            <option value="Select Year">Select Year</option>
            <option value="2023">2023</option>
            <option value="2017-2022">2017-2022</option>
            <option value="2011-2016">2011-2016</option>
            <option value="2005-2010">2005-2010</option>
            <option value="before 2005">before 2005</option>
          </select>
        </div>

        {/* Button to log preferences */}
        <button onClick={logPreferences}>Log Preferences</button>

        {/* Display all selected preferences at the bottom when the button is clicked */}
        {Object.keys(selectedPreferences).length > 0 && (
          <div className="selected-preferences">
            <h3>Selected Preferences:</h3>
            {Object.entries(selectedPreferences).map(([category, value]) => (
              <div key={category}>{`${category}: ${value}`}</div>
            ))}
          </div>
        )}
      </div>

      {/* Main Section with Movie Recommendations */}
      <div className="main-section">
        <header className="App-header">
          <h2>Here are your movie recommendations:</h2>
        </header>
        {/* Add your movie recommendation content here */}
      </div>
    </div>
  );
}


export default App;
