import React, { useEffect } from 'react';
import { Link } from 'react-router-dom';

import './index.css';

const Header = () => {
    useEffect(() => {
        const menuToggle = document.querySelector('.toggle');
        const navigation = document.querySelector('.navigation');

        menuToggle.onclick = function () {
            menuToggle.classList.toggle('active');
            navigation.classList.toggle('active');
        };
    }, []);

    return (
        <header>
            <Link to='/' className='logo'>
                Streams
            </Link>
            <div className='toggle'></div>
            <ul className='navigation'>
                <li>
                    <Link to='/' className='active'>
                        Login
                    </Link>
                </li>
                <li>
                    <Link to='/'>Name</Link>
                </li>
            </ul>
        </header>
    );
};

export default Header;
