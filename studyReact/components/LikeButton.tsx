import React, { useState, useEffect, useRef } from 'react'

const LikeButton: React.FC<{}> = () => {

    const [like, setLike] = useState(0)
    const likeRef = useRef(0)

    
    useEffect(()=> {
        console.log('document title effect is running')
        document.title = `点击了${like}次`
    }, [like])

    function handleAlertClick() {
        setTimeout(() => {
            alert('you clicked on ' + likeRef.current)
        }, 3000)
    }

    
    return (
        <> 
        <button onClick= { () => {setLike(like + 1); likeRef.current++}}>
            {like} 👍
        </button>
        <button onClick= {handleAlertClick}>Alert</button>
        </>
    )
}

export default LikeButton