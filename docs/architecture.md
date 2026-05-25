
# Architecture Overview

## Core Components

### 1. Network Layer
- Async TCP listener
- Session management
- Event-driven I/O

### 2. SIP Signalling Engine
- INVITE handling
- BYE teardown
- OPTIONS support

### 3. RTP Layer
- Packet abstraction
- Media stream management

### 4. Security Layer
- OpenSSL initialization
- Future SRTP support

### 5. Logging & Telemetry
- Structured JSON logs
- Future SNMP integration

## Scalability Goals
- Horizontal scaling
- Load balancing
- Multi-region deployment
